
int FUN_008ea6a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_008b83d0(&PTR_s_xf86_driver_name_00beaa1c,param_2);
  if (iVar1 == 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) {
      piVar2 = (int *)FUN_008b8f30(*(int *)(param_1 + 4),&DAT_00bd7d94);
      if ((piVar2 != (int *)0x0) && (*(int *)(*piVar2 + 0x14) != 0)) {
        iVar1 = (**(code **)(*(int *)(*piVar2 + 0x14) + 0x10))(param_1,param_2);
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}

