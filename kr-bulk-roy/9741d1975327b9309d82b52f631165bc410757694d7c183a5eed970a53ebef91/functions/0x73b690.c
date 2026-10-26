
void FUN_0073b690(void)

{
  char *pcVar1;
  char cVar2;
  char *unaff_ESI;
  undefined1 local_808;
  undefined1 local_807 [1023];
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_808 = 10;
  _memset(local_807,0,0x3ff);
  local_408 = '\n';
  _memset(local_407,0,0x3ff);
  cVar2 = FUN_0073b5d0();
  if (cVar2 != '\0') {
    _sprintf_s(&local_408,0x400,"D3DXTexture Error - %s\n",&local_808);
    if (unaff_ESI != (char *)0x0) {
      pcVar1 = unaff_ESI + 1;
      do {
        cVar2 = *unaff_ESI;
        unaff_ESI = unaff_ESI + 1;
      } while (cVar2 != '\0');
      if (unaff_ESI != pcVar1) {
        _sprintf_s(&local_408,0x400,"%s\n");
      }
    }
    FUN_006edd00(&local_408);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

