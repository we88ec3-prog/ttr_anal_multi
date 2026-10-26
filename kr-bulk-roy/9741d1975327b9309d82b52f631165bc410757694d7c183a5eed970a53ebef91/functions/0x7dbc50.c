
void FUN_007dbc50(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  undefined **local_70 [3];
  undefined **local_64 [3];
  int local_58;
  int local_54;
  undefined1 local_50 [4];
  int *local_4c;
  undefined4 local_48;
  char *local_40;
  undefined1 local_39;
  char *local_38;
  int *local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937a9b;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(local_14);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  uVar2 = DAT_00fb76a8;
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8 = 2;
    FUN_007d0fb0(&local_39);
    _atexit((_func_4879 *)&LAB_00bd09c0);
  }
  local_8 = 0xffffffff;
  iVar4 = FUN_007d0920(0);
  *local_34 = iVar4;
  if (iVar4 != 0) {
    piVar8 = local_34;
    if ((*(int *)(iVar4 + 0xdc) - *(int *)(iVar4 + 0xd8) & 0xfffffffcU) != 0) {
      local_40 = (char *)FUN_00891268(0xe8);
      local_8 = 3;
      if (local_40 == (char *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0077ebb0();
      }
      piVar8 = local_34;
      local_8 = 0xffffffff;
      (**(code **)(*piVar5 + 0x40))(*local_34);
      *piVar8 = (int)piVar5;
    }
    local_58 = 0;
    local_54 = 0;
    FUN_007c5f40(*piVar8,&local_58);
    uVar7 = local_54 - local_58 >> 0x1f;
    local_38 = (char *)((local_54 - local_58 ^ uVar7) - uVar7);
    local_48 = 0;
    piVar8[3] = (int)(float)(int)local_38;
    local_4c = (int *)FUN_00891268(0x2c);
    if (local_4c == (int *)0x0) {
      local_40 = (char *)0x0;
      std::exception::exception((exception *)local_70,&local_40);
      local_70[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_70,&DAT_00c857a8);
    }
    *local_4c = (int)local_4c;
    local_4c[1] = (int)local_4c;
    local_4c[2] = (int)local_4c;
    *(undefined1 *)(local_4c + 10) = 1;
    *(undefined1 *)((int)local_4c + 0x29) = 1;
    local_8._0_1_ = 4;
    local_8._1_3_ = 0;
    FUN_007c6ce0(uVar2,*piVar8,local_50);
    piVar5 = (int *)*local_4c;
    if (piVar5 != local_4c) {
      do {
        if ((uint)piVar5[8] < 0x10) {
          piVar8 = piVar5 + 3;
        }
        else {
          piVar8 = (int *)piVar5[3];
        }
        if ((DAT_00fe1df8 & 1) == 0) {
          DAT_00fe1df8 = DAT_00fe1df8 | 1;
          local_8._0_1_ = 5;
          DAT_00fe1e04 = 0;
          iVar4 = FUN_00891268(0x30);
          if (iVar4 == 0) {
            local_38 = (char *)0x0;
            std::exception::exception((exception *)local_64,&local_38);
            local_64[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_64,&DAT_00c857a8);
          }
          DAT_00fe1e00 = iVar4;
          *(int *)iVar4 = iVar4;
          *(int *)(DAT_00fe1e00 + 4) = DAT_00fe1e00;
          *(int *)(DAT_00fe1e00 + 8) = DAT_00fe1e00;
          *(undefined1 *)(DAT_00fe1e00 + 0x2c) = 1;
          *(undefined1 *)(DAT_00fe1e00 + 0x2d) = 1;
          _atexit((_func_4879 *)&LAB_00bcf1a0);
          local_8._0_1_ = 4;
        }
        iVar4 = FUN_00716740(piVar8);
        if (iVar4 != 0) {
          puVar6 = (undefined4 *)FUN_0079c590();
          if (0xf < (uint)puVar6[5]) {
            puVar6 = (undefined4 *)*puVar6;
          }
          piVar8 = piVar5 + 3;
          if (0xf < (uint)piVar5[8]) {
            piVar8 = (int *)*piVar8;
          }
          if ((DAT_00fe1ac0 & 1) == 0) {
            DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
            local_8._0_1_ = 7;
            FUN_007bb970();
            _atexit((_func_4879 *)&LAB_00bceac0);
          }
          local_8._0_1_ = 6;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
          (*DAT_00fe1ae0)(piVar8,puVar6);
          SetEvent(DAT_00fe1b2c);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
          local_8._0_1_ = 4;
          if (0xf < local_1c) {
            FUN_0089120c(local_30);
          }
        }
        if (*(char *)((int)piVar5 + 0x29) == '\0') {
          piVar8 = (int *)piVar5[2];
          if (*(char *)((int)piVar8 + 0x29) == '\0') {
            cVar1 = *(char *)(*piVar8 + 0x29);
            piVar5 = piVar8;
            piVar8 = (int *)*piVar8;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar8 + 0x29);
              piVar5 = piVar8;
              piVar8 = (int *)*piVar8;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x29);
            piVar3 = (int *)piVar5[1];
            piVar8 = piVar5;
            while ((piVar5 = piVar3, cVar1 == '\0' && (piVar8 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x29);
              piVar3 = (int *)piVar5[1];
              piVar8 = piVar5;
            }
          }
        }
        piVar8 = local_34;
      } while (piVar5 != local_4c);
    }
    piVar8[0xb] = 1;
    local_8 = 8;
    FUN_004ad180(*local_4c,local_4c);
    FUN_0089120c(local_4c);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

