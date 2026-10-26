
void FUN_00667020(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 local_e;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = *(undefined4 *)param_1[0x45];
  uVar2 = ((undefined4 *)param_1[0x45])[1];
  FUN_004adcd0();
  local_e = 0x9d;
  local_c = uVar1;
  local_8 = uVar2;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_e,10);
  }
  (**(code **)(*param_1 + 0xd4))();
  return;
}

