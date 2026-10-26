
uint FUN_004930e0(undefined4 param_1,undefined2 *param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_8;
  
  uVar1 = *param_2;
  uStack_8 = 0;
  if (param_3 == 0) {
    return 0;
  }
  if (param_4 == 2) {
    FUN_006db1f0(uVar1,param_3);
    timeGetTime();
    iVar2 = (**(code **)(*(int *)(in_ECX + 0xb8) + 4))(param_2,param_3,uVar1);
    timeGetTime();
    if ((iVar2 == 0x100) && (*(int *)(in_ECX + 0xbe8c) != 0)) {
      uStack_8 = 0x1000000;
    }
  }
  return uStack_8 >> 0x18;
}

