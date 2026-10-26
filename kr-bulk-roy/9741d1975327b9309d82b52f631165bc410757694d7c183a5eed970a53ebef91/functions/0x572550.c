
undefined4 FUN_00572550(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  int unaff_ESI;
  
  FUN_005725b0(param_2);
  FUN_005725b0(param_3);
  cVar1 = FUN_00572220();
  if (cVar1 != '\0') {
    uVar2 = FUN_00572670(in_ECX,*(undefined4 *)(unaff_ESI + 4));
    *(undefined4 *)(unaff_ESI + 4) = uVar2;
  }
  FUN_005725b0(param_1);
  return param_1;
}

