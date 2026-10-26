
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080dd00(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 ****ppppuVar6;
  LONG *Target;
  int in_ECX;
  char *pcVar7;
  int *piVar8;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009283f6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (*(int *)(in_ECX + 0xc) == 0) {
    if (DAT_00fba860 == 0) {
      piVar8 = (int *)(in_ECX + 0x18);
      piVar4 = piVar8;
      if (0xf < *(uint *)(in_ECX + 0x2c)) {
        piVar4 = (int *)*piVar8;
      }
      iVar3 = __strnicmp((char *)piVar4,"Scenario/",9);
      if (iVar3 != 0) {
        piVar4 = piVar8;
        if (0xf < *(uint *)(in_ECX + 0x2c)) {
          piVar4 = (int *)*piVar8;
        }
        iVar3 = __strnicmp((char *)piVar4,"Prologue/",9);
        if (iVar3 != 0) {
          piVar4 = piVar8;
          if (0xf < *(uint *)(in_ECX + 0x2c)) {
            piVar4 = (int *)*piVar8;
          }
          iVar3 = __strnicmp((char *)piVar4,"Voice/",6);
          if (iVar3 != 0) {
            if (0xf < *(uint *)(in_ECX + 0x2c)) {
              piVar8 = (int *)*piVar8;
            }
            FUN_006edb60("Trying to load non-registered sound file \'%s\'\n",piVar8);
            InterlockedExchange((LONG *)(in_ECX + 0x14),1);
            InterlockedExchange((LONG *)(in_ECX + 0x10),0);
            goto LAB_0080deed;
          }
        }
      }
    }
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 0;
      FUN_0080a3a0(uVar2);
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = 0xffffffff;
    }
    pcVar7 = _DAT_00fab02c;
    if (DAT_00fab040 < 0x10) {
      pcVar7 = &DAT_00fab02c;
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
    pcVar5 = pcVar7;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar7,(int)pcVar5 - (int)(pcVar7 + 1));
    local_8 = 1;
    if (*(uint *)(in_ECX + 0x2c) < 0x10) {
      pcVar7 = (char *)(in_ECX + 0x18);
    }
    else {
      pcVar7 = *(char **)(in_ECX + 0x18);
    }
    pcVar5 = pcVar7;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(pcVar7,(int)pcVar5 - (int)(pcVar7 + 1));
    iVar3 = FUN_0080da50(*(undefined4 *)(in_ECX + 0x3c));
    if (iVar3 == 0) {
      ppppuVar6 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar6 = local_30;
      }
      FUN_006edb60("SoundFile.Load(): File not found: %s",ppppuVar6);
      Target = (LONG *)(in_ECX + 0x14);
    }
    else {
      *(undefined4 *)(in_ECX + 0x34) = 600;
      Target = (LONG *)(in_ECX + 0xc);
    }
    InterlockedExchange(Target,1);
    InterlockedExchange((LONG *)(in_ECX + 0x10),0);
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
LAB_0080deed:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

