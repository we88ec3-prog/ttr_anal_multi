
void FUN_007947b0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_EAX;
  undefined4 *unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 0x18);
  if ((uint)((*(int *)(in_EAX + 0x1c) - iVar1) / 0x30) <= param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
  uVar2 = *(undefined4 *)(iVar1 + 0x1c + param_1 * 0x30);
  uVar3 = *(undefined4 *)(iVar1 + 0x20 + param_1 * 0x30);
  *unaff_ESI = *(undefined4 *)(iVar1 + 0x18 + param_1 * 0x30);
  unaff_ESI[1] = uVar2;
  unaff_ESI[2] = uVar3;
  return;
}

