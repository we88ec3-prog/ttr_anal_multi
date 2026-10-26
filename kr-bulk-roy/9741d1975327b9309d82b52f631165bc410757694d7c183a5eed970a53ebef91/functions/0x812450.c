
bool FUN_00812450(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  alSource3f(*(undefined4 *)(in_ECX + 8),0x1004,*param_1,param_1[1],param_1[2]);
  iVar2 = alGetError();
  alSourcei(*(undefined4 *)(in_ECX + 8),0x202,param_2);
  iVar3 = alGetError();
  bVar1 = iVar2 == 0 && iVar3 == 0;
  if (param_2 != 0) {
    alSourcef(*(undefined4 *)(in_ECX + 8),0x1021,0);
    alGetError();
    return bVar1;
  }
  alSourcef(*(undefined4 *)(in_ECX + 8),0x1021,0x3f800000);
  alGetError();
  return bVar1;
}

