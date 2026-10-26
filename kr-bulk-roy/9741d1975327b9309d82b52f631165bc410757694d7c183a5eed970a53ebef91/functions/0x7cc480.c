
void FUN_007cc480(undefined4 *param_1,void *param_2,void *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 in_EAX;
  undefined4 in_ECX;
  int unaff_EDI;
  void *local_8;
  
  puVar1 = param_1;
  D3DXCreateMeshFVF(in_ECX,unaff_EDI,0x220,0x12,in_EAX,param_1);
  param_1 = (void *)0x0;
  (**(code **)(*(int *)*puVar1 + 0x3c))((int *)*puVar1,0,&param_1);
  FID_conflict__memcpy(param_1,param_2,unaff_EDI * 0x18);
  (**(code **)(*(int *)*puVar1 + 0x40))((int *)*puVar1);
  local_8 = (void *)0x0;
  (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0,&local_8);
  FID_conflict__memcpy(local_8,param_3,param_4 * 2);
  (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1);
  return;
}

