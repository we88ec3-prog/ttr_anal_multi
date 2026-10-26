
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00811d10(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  
  uVar2 = 0;
  cVar1 = alIsExtensionPresent("EAX-RAM");
  uVar3 = 0;
  if (cVar1 == '\x01') {
    DAT_00fba8f0 = alGetProcAddress("EAXSetBufferMode");
    _DAT_00fba8f4 = alGetProcAddress("EAXGetBufferMode");
    uVar3 = uVar2;
    if ((DAT_00fba8f0 != 0) && (_DAT_00fba8f4 != 0)) {
      DAT_00fba8f8 = alGetEnumValue("AL_EAX_RAM_SIZE");
      DAT_00fba8fc = alGetEnumValue("AL_EAX_RAM_FREE");
      DAT_00fba900 = alGetEnumValue("AL_STORAGE_AUTOMATIC");
      DAT_00fba904 = alGetEnumValue("AL_STORAGE_HARDWARE");
      _DAT_00fba908 = alGetEnumValue("AL_STORAGE_ACCESSIBLE");
      if (((DAT_00fba8f8 != 0) &&
          (((DAT_00fba8fc != 0 && (DAT_00fba900 != 0)) && (DAT_00fba904 != 0)))) &&
         (_DAT_00fba908 != 0)) {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

