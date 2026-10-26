
void FUN_006b0060(undefined4 param_1)

{
  uint uVar1;
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 local_8;
  
  uVar1 = in_EAX - (int)in_ECX;
  while (4 < (int)(uVar1 & 0xfffffffc)) {
    local_8 = *(undefined4 *)((int)in_ECX + (uVar1 - 4));
    *(undefined4 *)((int)in_ECX + (uVar1 - 4)) = *in_ECX;
    FUN_006b00c0(0,(int)(uVar1 - 4) >> 2,&local_8,param_1);
    uVar1 = uVar1 - 4;
  }
  return;
}

