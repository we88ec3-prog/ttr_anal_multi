
void FUN_006be950(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *local_50;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bee0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != -1) {
    iVar2 = (*(int *)(DAT_00fc0c6c + 0xc) - *(int *)(DAT_00fc0c6c + 8)) / 0x34;
    piVar4 = (int *)0x0;
    if (iVar2 != 0) {
      piVar3 = *(int **)(DAT_00fc0c6c + 8);
      do {
        if (*piVar3 == param_1) {
          piVar4 = piVar3;
        }
        piVar3 = piVar3 + 0xd;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      if (piVar4 != (int *)0x0) {
        iVar2 = (piVar4[10] - piVar4[9]) / 0x24;
        local_50 = (int *)0x0;
        if (iVar2 != 0) {
          piVar3 = (int *)piVar4[9];
          do {
            if (*piVar3 == param_2) {
              local_50 = piVar3;
            }
            piVar3 = piVar3 + 9;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
          if (local_50 != (int *)0x0) {
            *(int *)(in_ECX + 0x174) = param_1;
            *(int *)(in_ECX + 0x178) = param_2;
            FUN_006beba0();
            FUN_004026e0(piVar4 + 2,0,0xffffffff);
            uVar5 = 0x18;
            local_8 = 0;
            FUN_00585620(0x18);
            uVar5 = FUN_00585330(uVar5);
            local_8 = 0xffffffff;
            FUN_00460780(uVar5);
            local_8 = 1;
            FUN_00757800();
            local_8 = 0xffffffff;
            if (7 < local_1c) {
              FUN_0089120c();
            }
            FUN_00585620();
            FUN_00585330();
            FUN_004ed610();
            local_8 = 2;
            FUN_00757800();
            local_8 = 0xffffffff;
            if (7 < local_1c) {
              FUN_0089120c();
            }
            if (local_50[1] == 0xff) {
              FUN_00757710();
            }
            else {
              FUN_00585620();
              FUN_00585330();
              FUN_004068f0();
              local_8 = 3;
              FUN_00757800();
              local_8 = 0xffffffff;
              FUN_004fa440();
            }
            FUN_00757800();
            FUN_006bed20();
          }
        }
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

