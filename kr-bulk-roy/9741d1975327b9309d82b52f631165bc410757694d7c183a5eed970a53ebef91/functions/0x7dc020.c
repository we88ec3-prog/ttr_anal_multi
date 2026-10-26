
void FUN_007dc020(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined1 local_34 [4];
  int *local_30;
  undefined4 local_2c;
  undefined **local_24 [3];
  char *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937a0c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  uVar3 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  local_2c = 0;
  local_30 = (int *)FUN_00891268(0x2c);
  if (local_30 != (int *)0x0) {
    *local_30 = (int)local_30;
    local_30[1] = (int)local_30;
    local_30[2] = (int)local_30;
    *(undefined1 *)(local_30 + 10) = 1;
    *(undefined1 *)((int)local_30 + 0x29) = 1;
    local_8 = 2;
    FUN_007c6ce0(uVar3,*param_1,local_34);
    piVar5 = (int *)*local_30;
    if (piVar5 != local_30) {
      do {
        if ((DAT_00fe1ac0 & 1) == 0) {
          DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
          local_8._0_1_ = 3;
          FUN_007bb970();
          _atexit((_func_4879 *)&LAB_00bceac0);
          local_8 = CONCAT31(local_8._1_3_,2);
        }
        FUN_007bcf60();
        if (*(char *)((int)piVar5 + 0x29) == '\0') {
          piVar2 = (int *)piVar5[2];
          if (*(char *)((int)piVar2 + 0x29) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x29);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x29);
              piVar5 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x29);
            piVar4 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x29);
              piVar4 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      } while (piVar5 != local_30);
    }
    if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
      *param_1 = 0;
    }
    param_1[0xb] = 0;
    local_8 = 4;
    FUN_004ad180(*local_30,local_30);
    FUN_0089120c(local_30);
    ExceptionList = local_10;
    return;
  }
  local_18[0] = (char *)0x0;
  std::exception::exception((exception *)local_24,local_18);
  local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_24,&DAT_00c857a8);
}

