
void FUN_0060b600(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    iVar2 = in_ECX[0x93];
    uVar1 = *(undefined1 *)((int)in_ECX + 0x249);
    iVar4 = in_ECX[0x92];
    iVar5 = FUN_0046fee0();
    piVar3 = *(int **)(iVar5 + 0xc);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x184))((char)iVar4,uVar1,iVar2);
      (**(code **)(*piVar3 + 0x188))();
    }
    (**(code **)(*in_ECX + 0x50))(*(undefined4 *)(iVar5 + 0xc));
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
  }
  return;
}

