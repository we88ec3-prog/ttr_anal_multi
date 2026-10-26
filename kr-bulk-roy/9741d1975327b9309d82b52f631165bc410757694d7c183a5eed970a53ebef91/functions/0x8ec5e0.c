
void FUN_008ec5e0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_008ec480();
  uVar1 = FUN_008b7f40(param_3,uVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x180) + param_2 * 4) = uVar1;
  return;
}

