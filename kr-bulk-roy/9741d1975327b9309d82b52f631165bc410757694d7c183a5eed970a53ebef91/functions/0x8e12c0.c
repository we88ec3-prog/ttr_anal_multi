
void FUN_008e12c0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int *param_8)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_EBX;
  
  _memset(unaff_EBX,0,0x2e08);
  unaff_EBX[1] = param_1;
  *unaff_EBX = in_EAX;
  uVar2 = FUN_008e06e0(8);
  FUN_008e0f30(unaff_EBX + 0x790,uVar2,param_2);
  FUN_008e0f30(unaff_EBX + 0x790,unaff_EBX + 0xb57,param_2);
  FUN_008e0f30(unaff_EBX + 0x790,unaff_EBX + 0xb57,param_2);
  unaff_EBX[0xb5f] = *(int *)(in_EAX + 0x24);
  unaff_EBX[0xb60] = *(int *)(in_EAX + 0x2c);
  unaff_EBX[0xb61] = *(int *)(in_EAX + 0x30);
  unaff_EBX[0xb62] = *param_8;
  unaff_EBX[0xb63] = param_8[1];
  unaff_EBX[0xb65] = param_3;
  unaff_EBX[0xb66] = param_4;
  unaff_EBX[0xb67] = param_5;
  unaff_EBX[0xb68] = param_6;
  unaff_EBX[0xb69] = param_7;
  *(undefined1 *)((int)unaff_EBX + 0x2d92) = *(undefined1 *)(in_EAX + 0x8d);
  iVar1 = *(int *)(in_EAX + 0xb8);
  unaff_EBX[0xb6a] = iVar1;
  iVar3 = *(int *)(in_EAX + 0xbc);
  unaff_EBX[0xb6b] = iVar3;
  iVar5 = iVar1;
  if (iVar1 < 0) {
    iVar5 = -iVar1;
  }
  iVar4 = iVar3;
  if (iVar3 < 0) {
    iVar4 = -iVar3;
  }
  if (iVar4 < iVar5) {
    iVar3 = iVar1;
    if (iVar1 < 0) {
      iVar3 = -iVar1;
    }
  }
  else if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  unaff_EBX[0xb6c] = iVar3 * 2;
  unaff_EBX[0xb6d] = 0x199a;
  *(undefined1 *)((int)unaff_EBX + 0x2d93) = 1;
  *(undefined2 *)(unaff_EBX + 0xb64) = 0;
  *(undefined1 *)(unaff_EBX + 0xb78) = 0;
  return;
}

