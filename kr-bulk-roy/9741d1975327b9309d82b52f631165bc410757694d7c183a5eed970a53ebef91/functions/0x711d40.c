
void FUN_00711d40(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  int in_EAX;
  int in_ECX;
  uint uVar3;
  
  puVar2 = (uint *)(*(int *)(*param_1 + 0xc) + in_ECX * 4);
  uVar1 = (in_EAX - in_ECX) - 1;
  uVar3 = (int)uVar1 >> 0x1f;
  if (0x1ffff < (int)((uVar1 ^ uVar3) - uVar3)) {
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1[3],"control structure too long",*(undefined4 *)(param_1[3] + 0x10));
  }
  *puVar2 = ((in_EAX - in_ECX) + 0x1fffe) * 0x4000 ^ *puVar2 & 0x3fff;
  return;
}

