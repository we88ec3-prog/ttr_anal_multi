
undefined4 FUN_006f3820(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  _memset((void *)(in_ECX + 8),0,0x100);
  puVar3 = (undefined4 *)(in_ECX + 4);
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&DAT_00bd66d4,puVar3,0);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(int *)*puVar3 + 0x2c))((int *)*puVar3,&DAT_00bd6994);
    piVar2 = (int *)*puVar3;
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*piVar2 + 0x34))(piVar2,param_2,6);
      if (-1 < iVar1) {
        return 0;
      }
      piVar2 = (int *)*puVar3;
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *puVar3 = 0;
    }
  }
  return 0x80004005;
}

