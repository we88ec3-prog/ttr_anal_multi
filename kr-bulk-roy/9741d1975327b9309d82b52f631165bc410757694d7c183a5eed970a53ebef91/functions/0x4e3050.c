
void FUN_004e3050(void)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f658;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(unaff_EDI + 0x692c);
  if (iVar1 != 0) {
    local_8 = 0;
    FUN_00833ad0(**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
    local_8 = 0xffffffff;
    FUN_0089120c(*(undefined4 *)(iVar1 + 4));
    FUN_0089120c(iVar1);
    *(undefined4 *)(unaff_EDI + 0x692c) = 0;
  }
  iVar1 = *(int *)(unaff_EDI + 0x6928);
  if (iVar1 != 0) {
    FUN_004d8e80(iVar1);
    FUN_0089120c(iVar1);
    *(undefined4 *)(unaff_EDI + 0x6928) = 0;
  }
  pvVar2 = *(void **)(unaff_EDI + 0x6924);
  if (pvVar2 != (void *)0x0) {
    _eh_vector_destructor_iterator_(pvVar2,0x210,10,FUN_004d3ec0);
    FUN_0089120c(pvVar2);
    *(undefined4 *)(unaff_EDI + 0x6924) = 0;
  }
  iVar1 = *(int *)(unaff_EDI + 0x6920);
  if (iVar1 != 0) {
    FUN_005095f0(uVar3);
    FUN_0089120c(iVar1);
    *(undefined4 *)(unaff_EDI + 0x6920) = 0;
  }
  if (*(int *)(unaff_EDI + 0x691c) != 0) {
    FUN_0089120c(*(int *)(unaff_EDI + 0x691c));
    *(undefined4 *)(unaff_EDI + 0x691c) = 0;
  }
  ExceptionList = local_10;
  return;
}

