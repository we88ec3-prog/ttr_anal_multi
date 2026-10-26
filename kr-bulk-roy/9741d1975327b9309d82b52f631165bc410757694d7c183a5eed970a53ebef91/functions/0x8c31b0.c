
void FUN_008c31b0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x1f8);
  iVar2 = (**(code **)(param_1 + 0x1fc))(param_1,0x636d6170,param_2,puVar1);
  if (iVar2 == 0) {
    iVar2 = FUN_008bc7a0(param_2,*puVar1,param_1 + 500);
    if (iVar2 != 0) {
      *puVar1 = 0;
    }
  }
  return;
}

