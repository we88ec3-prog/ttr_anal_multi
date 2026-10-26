
undefined4 FUN_00753930(void *param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  void *local_8;
  
  iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x2c))((int *)*unaff_ESI,0,0x70,&local_8,0x2000);
  if (iVar1 < 0) {
    return 0x80004005;
  }
  FID_conflict__memcpy(local_8,param_1,0x70);
  (**(code **)(*(int *)*unaff_ESI + 0x30))((int *)*unaff_ESI);
  return 0;
}

