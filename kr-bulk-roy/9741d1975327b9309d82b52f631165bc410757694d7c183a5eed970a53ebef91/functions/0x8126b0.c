
bool FUN_008126b0(undefined4 *param_1)

{
  int iVar1;
  
  alListener3f(0x1004,*param_1,param_1[1],param_1[2]);
  iVar1 = alGetError();
  return iVar1 == 0;
}

