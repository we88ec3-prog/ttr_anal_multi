
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0084b2b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  FUN_0084b340(param_1);
  if (*(int *)(in_ECX + 0x84) != *(int *)(in_ECX + 0x88)) {
    if (*(int *)(in_ECX + 0x94) == 0) {
      iVar1 = (**(code **)(_DAT_00000000 + 4))();
      if (*(int *)(iVar1 + 4) != -0x5ece0000) {
        return 0;
      }
    }
    (**(code **)(*param_2 + 0x28))
              (param_1,*(undefined4 *)(in_ECX + 0x94),*(int *)(in_ECX + 0x84),
               (*(int *)(in_ECX + 0x88) - *(int *)(in_ECX + 0x84)) / 0x50);
  }
  return 1;
}

