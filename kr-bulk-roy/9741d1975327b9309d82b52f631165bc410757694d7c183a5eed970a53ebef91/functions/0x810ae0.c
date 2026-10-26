
bool FUN_00810ae0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 0x10) = param_1;
  iVar1 = ov_pcm_seek(*(undefined4 *)(in_ECX + 4),param_1,param_1 >> 0x1f);
  return iVar1 != 0;
}

