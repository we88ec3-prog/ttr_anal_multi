
int FUN_00810250(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  iVar2 = 1;
  alGetSourcei(in_ECX[4],0x1016,&local_8);
  FUN_00810080();
  while (local_8 != 0) {
    local_8 = local_8 + -1;
    alSourceUnqueueBuffers(in_ECX[4],1,&local_c);
    FUN_00810080();
    iVar2 = FUN_00810170(local_c);
    if (0 < iVar2) {
      alSourceQueueBuffers(in_ECX[4],1,&local_c);
      FUN_00810080();
    }
  }
  local_8 = -1;
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x10))();
  }
  return iVar2;
}

