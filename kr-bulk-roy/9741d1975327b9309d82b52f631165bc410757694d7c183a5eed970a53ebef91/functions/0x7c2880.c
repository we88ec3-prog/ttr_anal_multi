
void FUN_007c2880(void)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 **ppuVar4;
  undefined4 uVar5;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 *local_64;
  undefined1 *local_60 [2];
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c [4];
  undefined4 local_2c;
  uint local_28;
  undefined1 *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00914d10;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = local_58[0] & 0xffffff00;
  pcVar3 = unaff_ESI;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
  local_c = 0;
  local_64 = (undefined1 *)FUN_007b6f30(local_58);
  if (local_64 != *(undefined1 **)(unaff_EDI + 4)) {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 == '\0') {
      ppuVar4 = &local_64;
      goto LAB_007c291e;
    }
  }
  local_60[0] = *(undefined1 **)(unaff_EDI + 4);
  ppuVar4 = local_60;
LAB_007c291e:
  local_60[0] = *ppuVar4;
  local_c = 0xffffffff;
  if (0xf < local_44) {
    FUN_0089120c(local_58[0]);
  }
  if (local_60[0] == *(undefined1 **)(unaff_EDI + 4)) {
    local_64 = (undefined1 *)FUN_00891268(0x20);
    if (local_64 == (undefined1 *)0x0) {
      local_64 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(local_64 + 0x14) = 0xf;
      *(undefined4 *)(local_64 + 0x10) = 0;
      *local_64 = 0;
      *(undefined4 *)(local_64 + 0x1c) = 0;
    }
    pcVar3 = unaff_ESI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
    local_28 = 0xf;
    local_2c = 0;
    local_3c[0] = local_3c[0] & 0xffffff00;
    pcVar3 = unaff_ESI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_ESI,(int)pcVar3 - (int)(unaff_ESI + 1));
    local_20 = local_64;
    local_c = 1;
    uVar5 = FUN_00552de0(local_3c);
    FUN_007e2910(unaff_EDI,local_60,uVar5);
    if (0xf < local_28) {
      FUN_0089120c(local_3c[0]);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

