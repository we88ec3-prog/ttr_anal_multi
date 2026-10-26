
void FUN_0086be90(void)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint *unaff_EDI;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  
  uVar1 = *unaff_EDI;
  if (uVar1 <= unaff_EDI[1]) {
    if (uVar1 == 0) {
      *unaff_EDI = 0x20;
    }
    else {
      *unaff_EDI = uVar1 * 2;
    }
    pvVar2 = _realloc((void *)unaff_EDI[2],*unaff_EDI * 0x54);
    unaff_EDI[2] = (uint)pvVar2;
  }
  iVar3 = unaff_EDI[1] * 0x54 + unaff_EDI[2];
  FUN_0077ea00();
  *(undefined4 *)(iVar3 + 0x2c) = in_stack_00000030;
  *(undefined4 *)(iVar3 + 0x30) = in_stack_00000034;
  *(undefined4 *)(iVar3 + 0x34) = in_stack_00000038;
  *(undefined4 *)(iVar3 + 0x38) = in_stack_0000003c;
  *(undefined4 *)(iVar3 + 0x3c) = in_stack_00000040;
  *(undefined4 *)(iVar3 + 0x40) = in_stack_00000044;
  *(undefined4 *)(iVar3 + 0x44) = in_stack_00000048;
  *(undefined4 *)(iVar3 + 0x48) = in_stack_0000004c;
  *(undefined4 *)(iVar3 + 0x4c) = in_stack_00000050;
  *(undefined4 *)(iVar3 + 0x50) = in_stack_00000054;
  unaff_EDI[1] = unaff_EDI[1] + 1;
  return;
}

