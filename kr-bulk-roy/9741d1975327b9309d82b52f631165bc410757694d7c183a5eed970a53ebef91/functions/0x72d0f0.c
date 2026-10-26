
void FUN_0072d0f0(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int *in_ECX;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int local_8;
  
  local_8 = 0;
  if (in_ECX[0x21] < 1) {
    uVar2 = in_EAX + 5;
  }
  else {
    if ((in_EAX != 0) && (*(int *)(*in_ECX + 0x2c) == 2)) {
      FUN_0072d710();
    }
    FUN_0072c2e0(in_ECX + 0x2c6);
    FUN_0072c2e0(in_ECX + 0x2c9);
    local_8 = FUN_0072cb40();
    uVar4 = in_ECX[0x5aa] + 10U >> 3;
    uVar2 = in_ECX[0x5ab] + 10U >> 3;
    if (uVar4 < uVar2) goto LAB_0072d169;
  }
  uVar4 = uVar2;
LAB_0072d169:
  if ((uVar4 < in_EAX + 4U) || (param_1 == 0)) {
    if ((in_ECX[0x22] == 4) || (uVar2 == uVar4)) {
      iVar1 = in_ECX[0x5af];
      uVar3 = (short)param_2 + 2;
      if (iVar1 < 0xe) {
        *(ushort *)(in_ECX + 0x5ae) = *(ushort *)(in_ECX + 0x5ae) | uVar3 << ((byte)iVar1 & 0x1f);
        in_ECX[0x5af] = iVar1 + 3;
      }
      else {
        *(ushort *)(in_ECX + 0x5ae) = *(ushort *)(in_ECX + 0x5ae) | uVar3 << ((byte)iVar1 & 0x1f);
        *(char *)(in_ECX[2] + in_ECX[5]) = (char)in_ECX[0x5ae];
        in_ECX[5] = in_ECX[5] + 1;
        *(undefined1 *)(in_ECX[5] + in_ECX[2]) = *(undefined1 *)((int)in_ECX + 0x16b9);
        iVar1 = in_ECX[0x5af];
        in_ECX[5] = in_ECX[5] + 1;
        in_ECX[0x5af] = iVar1 + -0xd;
        *(ushort *)(in_ECX + 0x5ae) = uVar3 >> (0x10U - (char)iVar1 & 0x1f);
      }
      FUN_0072d300(&DAT_00c082a8,&DAT_00c08728);
    }
    else {
      iVar1 = in_ECX[0x5af];
      uVar3 = (short)param_2 + 4;
      if (iVar1 < 0xe) {
        *(ushort *)(in_ECX + 0x5ae) = *(ushort *)(in_ECX + 0x5ae) | uVar3 << ((byte)iVar1 & 0x1f);
        in_ECX[0x5af] = iVar1 + 3;
      }
      else {
        *(ushort *)(in_ECX + 0x5ae) = *(ushort *)(in_ECX + 0x5ae) | uVar3 << ((byte)iVar1 & 0x1f);
        *(char *)(in_ECX[2] + in_ECX[5]) = (char)in_ECX[0x5ae];
        in_ECX[5] = in_ECX[5] + 1;
        *(undefined1 *)(in_ECX[5] + in_ECX[2]) = *(undefined1 *)((int)in_ECX + 0x16b9);
        iVar1 = in_ECX[0x5af];
        in_ECX[5] = in_ECX[5] + 1;
        in_ECX[0x5af] = iVar1 + -0xd;
        *(ushort *)(in_ECX + 0x5ae) = uVar3 >> (0x10U - (char)iVar1 & 0x1f);
      }
      FUN_0072cc10(in_ECX[0x2c7] + 1,in_ECX[0x2ca] + 1,local_8 + 1);
      FUN_0072d300(in_ECX + 0x25,in_ECX + 0x262);
    }
  }
  else {
    FUN_0072ce60(param_1);
  }
  FUN_0072bef0();
  if (param_2 != 0) {
    FUN_0072d860();
  }
  return;
}

