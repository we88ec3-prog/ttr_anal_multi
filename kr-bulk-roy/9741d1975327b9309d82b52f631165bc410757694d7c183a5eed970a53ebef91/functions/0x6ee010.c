
void FUN_006ee010(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int *in_EAX;
  int in_ECX;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_1 != 0) && (in_ECX != 0)) {
    uVar2 = in_EAX[2];
    if (in_ECX < 1) {
      uVar4 = uVar2 - param_1;
      if (uVar4 < uVar2) {
        iVar3 = uVar4 + in_ECX;
        do {
          uVar1 = *(ushort *)(*in_EAX + uVar4 * 2);
          *(undefined2 *)(*in_EAX + uVar4 * 2) = 0;
          *(ushort *)(*in_EAX + iVar3 * 2) =
               ((short)iVar3 + 1) * 0xde ^ ((short)uVar4 + 1) * 0xde ^ uVar1;
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 1;
        } while (uVar4 < (uint)in_EAX[2]);
      }
    }
    else {
      iVar3 = uVar2 - 1;
      if ((int)(uVar2 - param_1) <= iVar3) {
        iVar5 = iVar3 + in_ECX;
        do {
          uVar1 = *(ushort *)(*in_EAX + iVar3 * 2);
          *(undefined2 *)(*in_EAX + iVar3 * 2) = 0;
          *(ushort *)(*in_EAX + iVar5 * 2) =
               ((short)iVar5 + 1) * 0xde ^ ((short)iVar3 + 1) * 0xde ^ uVar1;
          iVar3 = iVar3 + -1;
          iVar5 = iVar5 + -1;
        } while (in_EAX[2] - param_1 <= iVar3);
        return;
      }
    }
  }
  return;
}

