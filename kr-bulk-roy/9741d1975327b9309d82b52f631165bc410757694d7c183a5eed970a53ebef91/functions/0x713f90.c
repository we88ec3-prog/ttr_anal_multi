
int FUN_00713f90(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (in_ECX[2] == 0) {
    uVar1 = (**(code **)(*in_ECX + 0x30))();
    (**(code **)(*in_ECX + 0x34))(0,0);
    iVar2 = FUN_0087dc3d(in_ECX[3]);
    in_ECX[2] = iVar2;
    if (in_ECX[3] != 0) {
      (**(code **)(*in_ECX + 0x10))(iVar2,in_ECX[3],1);
    }
    (**(code **)(*in_ECX + 0x34))(uVar1,0);
  }
  return in_ECX[2];
}

