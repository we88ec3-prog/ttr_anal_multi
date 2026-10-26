
undefined4 FUN_005fd1b0(int *param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (((0 < in_EAX) && (iVar2 = (**(code **)(*param_1 + 0x1ac))(), in_EAX <= iVar2)) &&
     (cVar1 = FUN_005f5ff0(), cVar1 != '\0')) {
    iVar3 = 0;
    iVar2 = (**(code **)(*param_1 + 0x1ac))();
    if (0 < iVar2) {
      do {
        cVar1 = FUN_005f60e0();
        if (cVar1 != '\0') {
          return 1;
        }
        iVar3 = iVar3 + 1;
        iVar2 = (**(code **)(*param_1 + 0x1ac))();
      } while (iVar3 < iVar2);
    }
    FUN_005fd3c0();
    return 1;
  }
  return 0;
}

