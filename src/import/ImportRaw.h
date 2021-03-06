/**********************************************************************

  Audacity: A Digital Audio Editor

  ImportRaw.h

  Dominic Mazzoni

**********************************************************************/

#ifndef __AUDACITY_IMPORT_RAW__
#define __AUDACITY_IMPORT_RAW__

#include "../MemoryX.h"

class TrackFactory;
class Track;
class WaveTrack;
class LabelTrack;
class DirManager;
class wxString;
class wxWindow;

#include <vector>

#ifdef __AUDACITY_OLD_STD__

class TrackHolder : public std::shared_ptr < Track >
{
public:
   // shared_ptr can construct from unique_ptr&& in newer std, but not older,
   // so define it here
   TrackHolder() = default;
   TrackHolder(std::unique_ptr<Track> &&that)
   {
      *this = std::move(that);
   }
   TrackHolder &operator=(std::unique_ptr<Track> &&that)
   {
      reset(that.release());
      return *this;
   }
   TrackHolder(std::unique_ptr<WaveTrack> &&that)
   {
      *this = std::move(that);
   }
   TrackHolder &operator=(std::unique_ptr<WaveTrack> &&that)
   {
      reset(that.release());
      return *this;
   }
   TrackHolder(std::unique_ptr<LabelTrack> &&that)
   {
      *this = std::move(that);
   }
   TrackHolder &operator=(std::unique_ptr<LabelTrack> &&that)
   {
      reset(that.release());
      return *this;
   }
};

using TrackHolders = std::vector<TrackHolder>;

#else

using TrackHolders = std::vector<std::unique_ptr<Track>>;

#endif


void ImportRaw(wxWindow *parent, const wxString &fileName,
   TrackFactory *trackFactory, TrackHolders &outTracks);

#endif
