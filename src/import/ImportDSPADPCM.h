/**********************************************************************

  Audacity: A Digital Audio Editor

  ImportPCM.h

  Jack Andersen

**********************************************************************/

#ifndef __AUDACITY_IMPORT_DSPADPCM__
#define __AUDACITY_IMPORT_DSPADPCM__

class ImportPluginList;
class UnusableImportPluginList;

void GetDSPADPCMImportPlugin(ImportPluginList *importPluginList,
                             UnusableImportPluginList *unusableImportPluginList);


#endif
