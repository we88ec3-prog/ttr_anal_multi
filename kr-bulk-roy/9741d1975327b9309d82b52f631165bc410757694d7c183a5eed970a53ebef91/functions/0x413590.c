
void FUN_00413590(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0xf43ba) {
    if (uVar1 == 0xf43b9) {
      FUN_0069b3a0();
      FUN_004181b0();
      return;
    }
    if (uVar1 == 0x387) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (uVar1 == 0x578) {
      iVar2 = *(int *)(param_1 + 8);
      if (iVar2 == *(int *)(in_ECX[0x24] + 0x20)) {
        FUN_00414680();
        FUN_004a45f0();
        return;
      }
      if (iVar2 == *(int *)(in_ECX[0x26] + 0x20)) {
        FUN_00414680();
        FUN_004a4660();
        return;
      }
      if (iVar2 == *(int *)(in_ECX[0x25] + 0x20)) {
        FUN_00414680();
        param_1 = CONCAT22(0xe9,(undefined2)param_1);
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
          return;
        }
      }
    }
  }
  else {
    switch(uVar1) {
    case 0xf43ba:
      FUN_0069b470();
      return;
    case 0xf43bb:
      iVar2 = FUN_0040afc0();
      FUN_004155b0(*(undefined4 *)(iVar2 + 0x14));
      return;
    case 0xf43bc:
      FUN_0069b540(in_ECX[0x20]);
      return;
    case 0xf43bd:
      FUN_00418220();
      return;
    case 0xf43c2:
      FUN_0069b670();
    }
  }
  return;
}

