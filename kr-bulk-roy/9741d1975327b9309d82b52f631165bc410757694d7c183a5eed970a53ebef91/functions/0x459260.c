
uint FUN_00459260(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint in_EAX;
  int iVar3;
  uint uVar4;
  int in_ECX;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    in_EAX = (**(code **)(*(int *)param_1[1] + 8))();
    if (in_EAX == 0xf4245) {
      uVar1 = *(undefined4 *)(param_1[1] + 0x2d0);
      uVar2 = *(undefined4 *)(in_ECX + 0x298);
      iVar3 = FUN_0045c050(uVar2,*(int *)(param_1[1] + 0x20) + 1);
      if (iVar3 == 1) {
        uVar4 = FUN_0045b110(uVar1);
        return uVar4;
      }
      in_EAX = iVar3 - 2;
      if (in_EAX == 0) {
        uVar4 = FUN_0045bc30(uVar2);
        return uVar4;
      }
    }
  }
  return in_EAX & 0xffffff00;
}

