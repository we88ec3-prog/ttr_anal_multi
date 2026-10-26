
void FUN_0073c870(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  if (param_3 != 0) {
    FUN_0073e030();
    iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,0,&local_10,param_3,0);
    if (-1 < iVar1) {
      FUN_0073dfa0(local_8 + 0xc,local_10,local_c,param_2);
      (**(code **)(*param_1 + 0x50))(param_1,0);
    }
  }
  return;
}

