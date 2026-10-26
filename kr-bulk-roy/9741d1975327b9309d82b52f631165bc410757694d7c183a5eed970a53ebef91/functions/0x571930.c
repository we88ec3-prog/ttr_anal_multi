
void FUN_00571930(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *unaff_ESI;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_8 = (float)(**(code **)(*(int *)*unaff_ESI + 0x14))();
  local_c = 48.0 / (float)(int)local_8;
  iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x18))();
  local_10 = 48.0 / (float)iVar1;
  local_14 = local_c;
  local_8 = local_10;
  (**(code **)(*(int *)*unaff_ESI + 0x24))(param_1,param_2,0,&local_14,0,0,0xffffffff);
  return;
}

