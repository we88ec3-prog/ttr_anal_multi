
undefined4 FUN_008b97e0(int param_1,uint param_2)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x14) == (code *)0x0) {
    if (param_2 <= *(uint *)(param_1 + 4)) goto LAB_008b9811;
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x14))(param_1,param_2,0,0);
    if (iVar1 == 0) {
LAB_008b9811:
      *(uint *)(param_1 + 8) = param_2;
      return 0;
    }
  }
  return 0x55;
}

