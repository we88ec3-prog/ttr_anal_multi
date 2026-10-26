
void FUN_00689880(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined4 in_ECX;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x104) = in_ECX;
  *(undefined4 *)(unaff_ESI + 0xf4) = param_1;
  *(undefined4 *)(unaff_ESI + 0xfc) = param_2;
  *(undefined4 *)(unaff_ESI + 0x100) = in_EAX;
  *(undefined4 *)(unaff_ESI + 0xf8) = param_4;
  *(undefined4 *)(*(int *)(unaff_ESI + 0x11c) + 0x16c) = in_EAX;
  iVar1 = *(int *)(unaff_ESI + 0xfc);
  iVar2 = *(int *)(unaff_ESI + 0x104);
  iVar3 = iVar1;
  if (iVar1 <= iVar2) {
    iVar3 = iVar2;
  }
  iVar4 = *(int *)(unaff_ESI + 0x100);
  if ((iVar3 < iVar4) && (iVar4 = iVar2, iVar2 < iVar1)) {
    iVar4 = iVar1;
  }
  FUN_0068ac30();
  (**(code **)(**(int **)(unaff_ESI + 0x11c) + 200))();
  *(int *)(unaff_ESI + 0x104) = iVar4;
  if (*(undefined4 **)(unaff_ESI + 0x120) == (undefined4 *)0x0) {
    *(undefined4 *)(unaff_ESI + 0x120) = param_3;
    return;
  }
  (**(code **)**(undefined4 **)(unaff_ESI + 0x120))(1);
  *(undefined4 *)(unaff_ESI + 0x120) = 0;
  *(undefined4 *)(unaff_ESI + 0x120) = param_3;
  return;
}

