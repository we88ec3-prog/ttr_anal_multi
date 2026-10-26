
void FUN_007121b0(int param_1)

{
  uint *puVar1;
  int *in_EAX;
  int iVar2;
  int *in_EDX;
  
  if (*in_EDX == 0xd) {
    puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + in_EDX[2] * 4);
    *puVar1 = *puVar1 ^ ((param_1 + 1) * 0x4000 ^ *(uint *)(*(int *)(*in_EAX + 0xc) + in_EDX[2] * 4)
                        ) & 0x7fc000;
    return;
  }
  if (*in_EDX == 0xe) {
    puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + in_EDX[2] * 4);
    *puVar1 = (param_1 + 1) * 0x800000 ^ *puVar1 & 0x7fffff;
    puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + in_EDX[2] * 4);
    *puVar1 = *puVar1 ^ (in_EAX[9] << 6 ^ *puVar1) & 0x3fc0;
    iVar2 = in_EAX[9] + 1;
    if ((int)(uint)*(byte *)(*in_EAX + 0x4b) < iVar2) {
      if (0xf9 < iVar2) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(in_EAX[3],"function or expression too complex",
                     *(undefined4 *)(in_EAX[3] + 0x10));
      }
      *(char *)(*in_EAX + 0x4b) = (char)iVar2;
    }
    in_EAX[9] = in_EAX[9] + 1;
  }
  return;
}

