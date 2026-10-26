
void FUN_00799f20(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *unaff_EDI;
  int *local_98;
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938306;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 0;
    FUN_007cdeb0(local_14);
    _atexit((_func_4879 *)&LAB_00bd09b0);
  }
  local_8 = 0xffffffff;
  FUN_007ceff0(&DAT_00fe3250,0);
  FUN_0079b060(unaff_EDI);
  FUN_007bb240();
  (**(code **)(*(int *)unaff_EDI[0x28] + 0xc))(unaff_EDI[0x26]);
  (**(code **)(*(int *)*unaff_EDI + 0xc))(1,1,1);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 1;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007ceff0(&DAT_00fe3250,1);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 2;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007ceff0(&DAT_00fe3250,4);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 3;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007ceff0(&DAT_00fe3250,2);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 4;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007ceff0(&DAT_00fe3250,3);
  if ((unaff_EDI[0xb] == 0) || (unaff_EDI[0xe] != 0)) {
    piVar4 = (int *)unaff_EDI[10];
    piVar2 = (int *)*piVar4;
    *piVar4 = (int)piVar4;
    *(int *)(unaff_EDI[10] + 4) = unaff_EDI[10];
    unaff_EDI[0xb] = 0;
    if (piVar2 != (int *)unaff_EDI[10]) {
      do {
        piVar4 = (int *)*piVar2;
        FUN_0089120c(piVar2);
        piVar2 = piVar4;
      } while (piVar4 != (int *)unaff_EDI[10]);
    }
  }
  else {
    iVar3 = *unaff_EDI;
    piVar4 = local_98;
    if (*(int *)(iVar3 + 0xec) != 0) {
      (**(code **)(**(int **)(iVar3 + 0xec) + 4))(*(int **)(iVar3 + 0xec));
      piVar4 = *(int **)(iVar3 + 0xec);
    }
    (**(code **)(*piVar4 + 0xec))(piVar4,1,&local_98);
    (**(code **)(*local_98 + 0x10))(local_98);
    (**(code **)(*piVar4 + 0xb4))(piVar4,2,local_54);
    (**(code **)(*piVar4 + 0xb4))(piVar4,3,local_94);
    (**(code **)(*(int *)unaff_EDI[0x24] + 0x14))((int *)unaff_EDI[0x24]);
    (**(code **)(*piVar4 + 0xb0))(piVar4,2,local_54);
    (**(code **)(*piVar4 + 0xb0))(piVar4,3,local_94);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x89,0);
    (**(code **)(*piVar4 + 0xe4))(piVar4,8,3);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x16,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x1b,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0xf,1);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x18,0);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x19,5);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x13,5);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x14,6);
    (**(code **)(*piVar4 + 0xe4))(piVar4,0x1c,0);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,0x18,0);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,0xb,0);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,1,2);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,2,0);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,4,2);
    (**(code **)(*piVar4 + 0x10c))(piVar4,0,5,2);
    (**(code **)(*piVar4 + 0x10c))(piVar4,1,1,1);
    (**(code **)(*piVar4 + 0x10c))(piVar4,1,4,1);
    (**(code **)(*piVar4 + 400))(piVar4,0,0,0,0);
    (**(code **)(*piVar4 + 0x1a0))(piVar4,0);
    (**(code **)(*piVar4 + 0x104))(piVar4,0,unaff_EDI[0x23]);
    (**(code **)(*piVar4 + 0x104))(piVar4,1,0);
    (**(code **)(*piVar4 + 0x164))(piVar4,0x142);
    piVar2 = *(int **)unaff_EDI[10];
    if (piVar2 != (int *)unaff_EDI[10]) {
      do {
        (**(code **)(*(int *)piVar2[2] + 8))(piVar4);
        if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)piVar2[2])(1);
          piVar2[2] = 0;
        }
        piVar2 = (int *)*piVar2;
      } while (piVar2 != (int *)unaff_EDI[10]);
    }
    piVar2 = (int *)unaff_EDI[10];
    piVar1 = (int *)*piVar2;
    *piVar2 = (int)piVar2;
    *(int *)(unaff_EDI[10] + 4) = unaff_EDI[10];
    unaff_EDI[0xb] = 0;
    if (piVar1 != (int *)unaff_EDI[10]) {
      do {
        piVar2 = (int *)*piVar1;
        FUN_0089120c(piVar1);
        piVar1 = piVar2;
      } while (piVar2 != (int *)unaff_EDI[10]);
    }
    (**(code **)(*local_98 + 0x14))(local_98);
    (**(code **)(*local_98 + 8))(local_98);
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  (**(code **)(*(int *)*unaff_EDI + 0xc))(1,1,1);
  if (unaff_EDI[0xb3] != unaff_EDI[0xb4]) {
    iVar3 = FUN_0079c4b0(unaff_EDI[0xb4]);
    unaff_EDI[0xb4] = iVar3;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

