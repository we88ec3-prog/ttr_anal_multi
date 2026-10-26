
undefined4 FUN_0076fcd0(undefined4 *param_1,void *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  int *in_ECX;
  
  puVar2 = param_1;
  (**(code **)(*in_ECX + 0x68))();
  piVar1 = (int *)*puVar2;
  iVar3 = (**(code **)(*piVar1 + 0x2c))(piVar1,0,in_EAX * 0x14,&param_1,0);
  if (iVar3 < 0) {
    return 0x80004005;
  }
  FID_conflict__memcpy(param_1,param_2,in_EAX * 0x14);
  piVar1 = (int *)*puVar2;
  (**(code **)(*piVar1 + 0x30))(piVar1);
  return 0;
}

