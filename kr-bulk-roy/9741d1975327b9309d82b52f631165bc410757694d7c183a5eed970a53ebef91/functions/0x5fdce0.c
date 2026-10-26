
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005fdce0(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_104c [4];
  int iStack_1048;
  int iStack_1044;
  int iStack_1040;
  int iStack_103c;
  undefined2 uStack_1038;
  int iStack_1034;
  int *local_1030;
  int iStack_102c;
  undefined2 uStack_1028;
  undefined1 auStack_1026 [4094];
  int iStack_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e9b6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_104c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffefa8;
  ExceptionList = &local_14;
  local_1030 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar4 = DAT_00f94300;
  local_c = 0xffffffff;
  iVar3 = (**(code **)(*in_ECX + 0x1ac))();
  if (iVar3 == 1) {
    piVar5 = (int *)(iVar4 + 0x16f8);
  }
  else {
    piVar5 = (int *)0x0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iStack_1040 = 0;
  if (DAT_00f94300 != -0x16f8) {
    iStack_1040 = *(int *)(DAT_00f94300 + 0x2398);
  }
  iStack_1048 = 0;
  if (piVar5 != (int *)0x0) {
    uStack_1028 = 0xfa;
    iStack_28 = 2;
    iStack_103c = 1;
    if (0 < iStack_1040) {
      do {
        piVar6 = piVar5 + 8;
        if (iStack_103c - 1U < 100) {
          if ((((piVar5[0xb] != 0) && (piVar5[10] != 0)) && (piVar6 != (int *)0x0)) &&
             ((*piVar6 == 0x10 || (*piVar6 == 0x19)))) {
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 2;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            iStack_1044 = piVar5[0xb];
            FUN_008438c0(&iStack_1044);
            if (iStack_1034 == DAT_00f8d91c) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(iStack_1034 + 0x10);
            }
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_c = 3;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_c = 0xffffffff;
            }
            iStack_1044 = *(int *)(iVar4 + 0x50);
            FUN_008438c0(&iStack_1044);
            if ((iStack_102c == DAT_00f8d91c) || (*(int *)(iStack_102c + 0x10) == 0)) {
              iVar4 = FUN_008fed10();
            }
            else {
              iVar4 = FUN_008fed10();
            }
            iStack_1048 = iVar4;
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 4;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            if (iVar4 < DAT_00f94244) {
              iVar4 = *piVar6;
              uVar1 = (**(code **)(*local_1030 + 0x1ac))();
              uStack_1038 = CONCAT11((undefined1)iStack_103c,uVar1);
              if (iStack_28 + 3U < 0x1001) {
                *(undefined2 *)(auStack_1026 + iStack_28 + -2) = uStack_1038;
                auStack_1026[iStack_28] = (char)iVar4;
                iStack_28 = iStack_28 + 3;
              }
            }
          }
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
        }
        iStack_103c = iStack_103c + 1;
        piVar5 = piVar6;
      } while (iStack_103c <= iStack_1040);
    }
    (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_1028,iStack_28);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_104c);
  return;
}

