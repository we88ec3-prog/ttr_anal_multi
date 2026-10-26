
int FUN_00717f60(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  if (in_ECX[2] == 0) {
    uVar2 = (**(code **)(*in_ECX + 0x30))();
    (**(code **)(*in_ECX + 0x34))(0,0);
    iVar3 = FUN_0087dc3d(in_ECX[3]);
    pcVar1 = *(code **)(*in_ECX + 0x10);
    in_ECX[2] = iVar3;
    (*pcVar1)(iVar3,in_ECX[3],1);
    (**(code **)(*in_ECX + 0x34))(uVar2,0);
  }
  return in_ECX[2];
}

