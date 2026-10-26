
void FUN_00534290(void)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  short *psVar9;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912d24;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar5;
  if (DAT_00fe1be4 != 0) {
    piVar6 = (int *)*DAT_00fe1be0;
    *DAT_00fe1be0 = (int)DAT_00fe1be0;
    DAT_00fe1be0[1] = (int)DAT_00fe1be0;
    DAT_00fe1be4 = 0;
    if (piVar6 != DAT_00fe1be0) {
      do {
        piVar2 = (int *)*piVar6;
        FUN_0089120c(piVar6,uVar5);
        piVar6 = piVar2;
      } while (piVar2 != DAT_00fe1be0);
    }
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  piVar6 = DAT_00f8d928;
  piVar2 = DAT_00f8d92c;
  piVar3 = DAT_00fe1be0;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
    piVar2 = DAT_00f8d92c;
    piVar3 = DAT_00fe1be0;
  }
  do {
    piVar4 = DAT_00f8d92c;
    DAT_00fe1be0 = piVar3;
    if (piVar6 == DAT_00f8d92c) {
      piVar6 = (int *)*piVar3;
      piVar4 = *(int **)*piVar3;
      DAT_00f8d92c = piVar2;
      while (piVar4 != piVar3) {
        if (piVar6[2] == piVar4[2]) {
          piVar2 = (int *)*piVar4;
          *piVar6 = (int)piVar2;
          piVar2[1] = (int)piVar6;
          FUN_0089120c(piVar4);
          DAT_00fe1be4 = DAT_00fe1be4 + -1;
          piVar4 = piVar2;
        }
        else {
          piVar6 = piVar4;
          piVar4 = (int *)*piVar4;
        }
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    DAT_00f8d92c = piVar2;
    iVar7 = FUN_0051bfc0();
    if (iVar7 == 0) {
      psVar9 = (short *)*piVar6;
      if (7 < *(uint *)(psVar9 + 10)) {
        psVar9 = *(short **)psVar9;
      }
      local_30[0] = local_30[0] & 0xffff0000;
      local_1c = 7;
      local_20 = 0;
      psVar8 = psVar9;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar8 - (int)(psVar9 + 1) >> 1);
      local_8 = 2;
      iVar7 = FUN_00466df0(local_30,&DAT_00c0f21c,3);
      if (iVar7 == -1) {
        piVar2 = DAT_00fe1be0 + 1;
        iVar7 = FUN_0074d700(DAT_00fe1be0,DAT_00fe1be0[1],*piVar6 + 0x1c);
        if (DAT_00fe1be4 == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        DAT_00fe1be4 = DAT_00fe1be4 + 1;
        *piVar2 = iVar7;
        **(int **)(iVar7 + 4) = iVar7;
      }
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
    piVar6 = piVar6 + 1;
    piVar2 = DAT_00f8d92c;
    piVar3 = DAT_00fe1be0;
    DAT_00f8d92c = piVar4;
  } while( true );
}

