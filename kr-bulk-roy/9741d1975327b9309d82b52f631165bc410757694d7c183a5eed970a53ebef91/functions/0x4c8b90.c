
void FUN_004c8b90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_004cab80(param_1,param_2);
  if ((in_ECX[0xdc] != 0) && (in_ECX[0x57] != 0)) {
    iVar1 = *(int *)(in_ECX[0x57] + 4);
    uVar2 = (**(code **)(*in_ECX + 0x4c))();
    (**(code **)(iVar1 + 4))(uVar2);
  }
  return;
}

