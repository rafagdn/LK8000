/*
   LK8000 Tactical Flight Computer -  WWW.LK8000.IT
   Released under GNU/GPL License v.2
   See CREDITS.TXT file for authors and copyrights

   $Id$
*/

#include "externs.h"
#include "Utils.h"
#include "McReady.h"
#include "Modeltype.h"

#if NEWPROFILES
//
// Set all default values for configuration.
// We need to set runtime variables later, that make use of 
// configuration values. One setting for configuration, and the
// runtime equivalent of the same setting, for the case when it
// is possible to change runtime with a button for example such value.
//
void LKProfileResetDefault(void) {

  #if TESTBENCH
  StartupStore(TEXT(". ProfileResetDefault%s"),NEWLINE);
  #endif

  Units::CoordinateFormat = (CoordinateFormats_t)cfDDMMSS;

  // default Speed unit 
  Speed=2; 
  TaskSpeed = 2;
  Distance=2;
  Altitude=1;
  Lift=1;

  //
  // Default infobox groups configuration
  // Should be different for each aircraft category
  //
  InfoType[0] = 1008146198;
  InfoType[1] = 1311715074;
  InfoType[2] = 923929365;
  InfoType[3] = 975776319;
  InfoType[4] = 956959267;
  InfoType[5] = 1178420506;
  InfoType[6] = 1410419993;
  InfoType[7] = 1396384771;
  InfoType[8] = 387389207;

  DisplayOrientation_Config=TRACKUP;

  DisplayTextType=0;

  AltitudeMode = Temp;

  ClipAltitude = Temp;

  AltWarningMargin = Temp;

  AirspaceWarningRepeatTime = Temp;

  AirspaceWarningVerticalMargin = Temp;

  AirspaceWarningDlgTimeout = Temp;

  AirspaceWarningMapLabels = Temp;
	
  SafetyAltitudeMode = Temp;

  SAFETYALTITUDEARRIVAL = (double)Temp;

  SAFETYALTITUDETERRAIN = (double)Temp;

  SAFTEYSPEED=50.0;

  WindCalcSpeed=27.778;

  WindCalcTime=Temp;

  SectorType = Temp;

  SectorRadius = 10000;


  for(i=0;i<AIRSPACECLASSCOUNT;i++)
    {
      MapWindow::iAirspaceMode[i] = GetRegistryAirspaceMode(i);

      Temp= MapWindow::iAirspaceBrush[i];
      MapWindow::iAirspaceBrush[i] =			(int)Temp;

      Temp= MapWindow::iAirspaceColour[i];
      MapWindow::iAirspaceColour[i] =			(int)Temp;

      if (MapWindow::iAirspaceColour[i]>= NUMAIRSPACECOLORS) {
        MapWindow::iAirspaceColour[i]= 0;
      }

      if (MapWindow::iAirspaceBrush[i]>= NUMAIRSPACEBRUSHES) {
        MapWindow::iAirspaceBrush[i]= 0;
      }

    }

  MapWindow::SetAirSpaceFillType((MapWindow::EAirspaceFillType)Temp);

  Temp = MapWindow::GetAirSpaceOpacity();
  MapWindow::SetAirSpaceOpacity(Temp);

  Temp = MapWindow::bAirspaceBlackOutline;
  MapWindow::bAirspaceBlackOutline = (Temp == 1);

  TrailActive = Temp;

  MapWindow::EnableTrailDrift = (Temp==1);

  EnableThermalLocator = Temp;

  EnableTopology = (Temp == 1);

  EnableTerrain = (Temp == 1);

  FinalGlideTerrain = Temp;

  AutoWindMode = Temp;

  MapWindow::zoom.CircleZoom(Temp == 1);

  WindUpdateMode = Temp;

  HomeWaypoint = -1;

  Alternate1 = -1;

  Alternate2 = -1;

  MapWindow::SnailWidthScale = Temp;

  TeamCodeRefWaypoint = Temp;

  StartLine = 1;

  StartRadius = 1000;

  FinishLine = 1;

  FinishRadius = 1000;

  AIRSPACEWARNINGS = Temp;

  WarningTime = max(10,Temp);

  AcknowledgementTime = max(10,Temp);

  EnableAutoBacklight = 1;

  EnableAutoSoundVolume = 1;

  AircraftCategory = 0;

  if (ISPARAGLIDER)
	AATEnabled=TRUE;
  else
	AATEnabled=FALSE;

  ExtendedVisualGlide = 0;

  if (ScreenLandscape)
	Look8000 = (Look8000_t)lxcAdvanced;
  else
	Look8000 = (Look8000_t)lxcStandard;  

  CheckSum = 1;

  PGCruiseZoom=4;
  PGClimbZoom=1;
  AutoOrientScale=10;

  PGOpenTimeH=12;
  PGOpenTimeM=0;
  PGNumberOfGates=0;
  PGGateIntervalTime=30;
  PGStartOut=0;

  LKTopoZoomCat05=9999;
  LKTopoZoomCat10=9999;
  LKTopoZoomCat20=9999;
  LKTopoZoomCat30=9999;
  LKTopoZoomCat40=9999;
  LKTopoZoomCat50=9999;
  LKTopoZoomCat60=9999;
  LKTopoZoomCat70=9999;
  LKTopoZoomCat80=9999;
  LKTopoZoomCat90=9999;
  LKTopoZoomCat100=9999;
  LKTopoZoomCat110=9999;

  LKMaxLabels=70;

  IphoneGestures = (IphoneGestures_t)iphDisabled;

  PollingMode = (PollingMode_t)pollmodeDisabled;

  LKVarioBar = (LKVarioBar_t)vBarDisabled;

  LKVarioVal = (LKVarioVal_t)vValVarioVario;

  OutlinedTp = (OutlinedTp_t)otLandable;

  TpFilter = (TpFilter_t)TfNoLandables;

  OverColor = (OverColor_t)OcBlack;

  DeclutterMode = (DeclutterMode_t)dmMedium;

  // full size overlay by default
  OverlaySize = 0;

  BarOpacity = 65;

  #ifdef PPC2002  
  FontRenderer = 1; // AntiAliasing
  #else
  FontRenderer = 0; // ClearType Compatible
  #endif

  GPSAltitudeOffset = 0;

  UseGeoidSeparation = 1;

  PressureHg = 0;

  CustomKeyTime = 700;
  CustomKeyModeCenter = (CustomKeyMode_t)ckDisabled;

  CustomKeyModeLeft = (CustomKeyMode_t)ckDisabled;
  CustomKeyModeRight = (CustomKeyMode_t)ckDisabled;
  CustomKeyModeAircraftIcon = (CustomKeyMode_t)ckDisabled;
  CustomKeyModeLeftUpCorner = (CustomKeyMode_t)ckMultitargetRotate;
  CustomKeyModeRightUpCorner = (CustomKeyMode_t)ckMultitargetMenu;
  CustomKeyModeCenterScreen = (CustomKeyMode_t)ckWhereAmI;

  MapBox = (MapBox_t)mbBoxed; 

  // Units labels printout
  if ((ScreenSize == (ScreenSize_t)ss240x320) ||
      (ScreenSize == (ScreenSize_t)ss272x480) ||
      (ScreenSize == (ScreenSize_t)ss320x240) )
	HideUnits = 1;
  else
	HideUnits = 0;


  ActiveMap = 0;

  BestWarning=1;

  ThermalBar=0;

  McOverlay=1;

  TrackBar=1;

  PGOptimizeRoute=1;

  GlideBarMode = (GlideBarMode_t)gbDisabled;

  ArrivalValue = (ArrivalValue_t)avAltitude;

  // 1 is showing all airports and declutter only unneeded outlandings
  NewMapDeclutter = 1;

  // This need AircraftCategory been set !
  AverEffTime = (AverEffTime_t)ae2minutes; 

  BgMapColor = 2;

  debounceTimeout = 250;

  // new appearance variables

  Appearance.IndLandable = (IndLandable_t)wpLandableAltA;

  Appearance.InverseInfoBox = 1;

  needclipping=false;

  Appearance.InfoBoxModel = 

  Appearance.DefaultMapWidth = 

  AutoAdvance = 1;

  AutoMcMode_Config = 

  AutoMacCready_Config = 

  UseTotalEnergy_Config=

  WaypointsOutOfRange = 

  EnableFAIFinishHeight = 

  Handicap = 

  EnableExternalTriggerCruise = 

  UTCOffset = 0;

  AutoZoom_Config=false;

  MenuTimeoutMax = 

  LockSettingsInFlight = 0;

  LoggerShortName = 0;

  EnableFLARMMap = 

  TerrainContrast = 

  TerrainBrightness = 

  TerrainRamp_Config = 

  MapWindow::GliderScreenPosition = (int)Temp;
  MapWindow::GliderScreenPositionY = MapWindow::GliderScreenPosition;


  BallastSecsToEmpty = Temp;

  SetSystemTimeFromGPS = ?

  AutoForceFinalGlide = ?

  UseCustomFonts = 0;

  AlarmMaxAltitude1 = 0;

  AlarmMaxAltitude2 = 0;

  AlarmMaxAltitude3 = 0;

  FinishMinHeight = 0;

  StartHeightRef = ?

  StartMaxHeight = ?
  
  StartMaxHeightMargin = 

  StartMaxSpeed = 

  StartMaxSpeedMargin = 

  EnableNavBaroAltitude = 1;

  Orbiter = 1;
  Shading = 1;
  OverlayClock = 0;

  // default BB and IP is all ON
  ConfBB1 = 1;
  ConfBB2 = 1;
  ConfBB3 = 1;
  ConfBB4 = 1;
  ConfBB5 = 1;
  ConfBB6 = 1;
  ConfBB7 = 1;
  ConfBB8 = 1;
  ConfBB9 = 1;

  ConfIP11 = 1;
  ConfIP12 = 1;
  ConfIP13 = 1;
  ConfIP14 = 1;
  ConfIP15 = 1;
  ConfIP16 = 1;
  ConfIP21 = 1;
  ConfIP22 = 1;
  ConfIP23 = 1;
  ConfIP24 = 1;
  ConfIP31 = 1;
  ConfIP32 = 1;
  ConfIP33 = 1;

  LoggerTimeStepCruise = 

  LoggerTimeStepCircling = 

  GlidePolar::SafetyMacCready = 

  DisableAutoLogger = false;


}



#if 0

void ReadPort1Settings(DWORD *PortIndex, DWORD *SpeedIndex, DWORD *Bit1Index)
{
  DWORD Temp=0;

  if(GetFromRegistry(szRegistryPort1Index,&Temp)==ERROR_SUCCESS)
    (*PortIndex) = Temp;

  if(GetFromRegistry(szRegistrySpeed1Index,&Temp)==ERROR_SUCCESS)
    (*SpeedIndex) = Temp;

  if(GetFromRegistry(szRegistryBit1Index,&Temp)==ERROR_SUCCESS)
    (*Bit1Index) = Temp;
}


void ReadPort2Settings(DWORD *PortIndex, DWORD *SpeedIndex, DWORD *Bit2Index)
{
  DWORD Temp=0;

  if(GetFromRegistry(szRegistryPort2Index,&Temp)==ERROR_SUCCESS)
    (*PortIndex) = Temp;

  if(GetFromRegistry(szRegistrySpeed2Index,&Temp)==ERROR_SUCCESS)
    (*SpeedIndex) = Temp;

  if(GetFromRegistry(szRegistryBit2Index,&Temp)==ERROR_SUCCESS)
    (*Bit2Index) = Temp;
}



int GetRegistryAirspaceMode(int i) {
  DWORD Temp= 3; // display + warnings
  GetFromRegistry(szRegistryAirspaceMode[i],&Temp);
  return Temp;
}



void ReadDeviceSettings(const int devIdx, TCHAR *Name){

  Name[0] = '\0';

  if (devIdx == 0){
    GetRegistryString(szRegistryDeviceA , Name, DEVNAMESIZE);
  }

  if (devIdx == 1){
    GetRegistryString(szRegistryDeviceB , Name, DEVNAMESIZE);
  }
    if (_tcslen(Name)==0) _tcscpy(Name,_T(DEV_DISABLED_NAME));
    return;

}


#ifdef PNA
// LOAD ModelType directly at startup
extern bool SetModelName(DWORD Temp);

bool SetModelType() {

  TCHAR sTmp[100];
  TCHAR szRegistryInfoBoxModel[]= TEXT("AppInfoBoxModel");
  DWORD Temp=0;

  GetFromRegistry(szRegistryInfoBoxModel, &Temp);
  
  if ( SetModelName(Temp) != true ) {
	_stprintf(sTmp,_T(". SetModelType failed: probably no registry entry%s"), NEWLINE);
	StartupStore(sTmp);
	GlobalModelType=MODELTYPE_PNA_PNA;
	_tcscpy(GlobalModelName,_T("GENERIC"));  // 100820
	return false;
  } else {
	GlobalModelType = Temp;
  }
  
  _stprintf(sTmp,_T(". SetModelType: Name=<%s> Type=%d%s"),GlobalModelName, GlobalModelType,NEWLINE);
  StartupStore(sTmp);
  return true;
}
#endif



#endif // 0


#endif // NEWPROFILES