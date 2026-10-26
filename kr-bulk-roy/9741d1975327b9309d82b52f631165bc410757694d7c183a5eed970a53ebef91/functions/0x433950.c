
uint * FUN_00433950(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  
  puVar3 = param_1;
  uVar1 = *param_1;
  if (uVar1 != *param_2) {
    std::_Lockit::_Lockit((_Lockit *)&param_1,0);
    iVar2 = *(int *)(uVar1 + 4);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      *(int *)(uVar1 + 4) = iVar2 + -1;
    }
    iVar2 = *(int *)(uVar1 + 4);
    FUN_0087dd6f();
    puVar4 = (undefined4 *)(~-(uint)(iVar2 != 0) & uVar1);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar1 = *param_2;
    *puVar3 = uVar1;
    std::_Lockit::_Lockit((_Lockit *)&param_2,0);
    if (*(int *)(uVar1 + 4) != -1) {
      *(int *)(uVar1 + 4) = *(int *)(uVar1 + 4) + 1;
    }
    FUN_0087dd6f();
  }
  return puVar3;
}

