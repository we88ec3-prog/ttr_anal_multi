
undefined4 FUN_006f3ef0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  piVar1 = (int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  iVar3 = (**(code **)(*param_1 + 0xc))(param_1,&DAT_00bd66e4,piVar1,0);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*(int *)*piVar1 + 0x2c))((int *)*piVar1,&DAT_00bd6da4);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,param_2,6);
      if (-1 < iVar3) {
        return 0;
      }
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        *piVar1 = 0;
      }
    }
  }
  return 0x80004005;
}

