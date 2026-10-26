
void FUN_0043006d(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int unaff_EBP;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  undefined4 in_stack_0000003c;
  int *in_stack_00000040;
  undefined4 in_stack_00000048;
  uint in_stack_0000005c;
  uint in_stack_00000064;
  void *in_stack_0000006c;
  
  puVar3 = (undefined4 *)FUN_00430960();
  *(undefined4 *)(unaff_EBP + 0x10) = *puVar3;
  *(undefined4 *)(unaff_EBP + 0x14) = puVar3[1];
  (**(code **)(*in_stack_00000040 + 8))();
  uVar2 = in_stack_00000030;
  puVar3 = (undefined4 *)
           FUN_0042fdf0(in_stack_00000030,&stack0x00000040,*(undefined4 *)(unaff_EBP + 0x10),
                        *(undefined4 *)(unaff_EBP + 0x14));
  uVar1 = *puVar3;
  *(undefined4 *)(unaff_EBP + 0x10) = uVar1;
  *(undefined4 *)(unaff_EBP + 0x14) = puVar3[1];
  *(undefined4 *)(in_stack_00000034 + 0x20) = 0;
  *(undefined4 *)(in_stack_00000034 + 0x24) = 0;
  FUN_00430960(uVar2,in_stack_0000003c,uVar1);
  if (0xf < in_stack_0000005c) {
    FUN_0089120c();
  }
  ExceptionList = in_stack_0000006c;
  __security_check_cookie(in_stack_00000064 ^ (uint)&stack0x0000001c);
  return;
}

