
void FUN_005c7410(void)

{
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  undefined2 *puVar3;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009128e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = unaff_EDI[1];
  if ((in_ECX < uVar1) && (uVar2 = *unaff_EDI, uVar2 <= in_ECX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_005c7500(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined2 *)unaff_EDI[1];
    in_ECX = ((int)(in_ECX - uVar2) / 0x2c) * 0x2c + *unaff_EDI;
    local_8 = 0;
    if (puVar3 == (undefined2 *)0x0) goto LAB_005c74e9;
    *(undefined4 *)(puVar3 + 10) = 7;
    *(undefined4 *)(puVar3 + 8) = 0;
    *puVar3 = 0;
    FUN_004026e0(in_ECX,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_005c7500(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar3 = (undefined2 *)unaff_EDI[1];
    local_8 = 2;
    if (puVar3 == (undefined2 *)0x0) goto LAB_005c74e9;
    *(undefined4 *)(puVar3 + 10) = 7;
    *(undefined4 *)(puVar3 + 8) = 0;
    *puVar3 = 0;
    FUN_004026e0(in_ECX,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,3);
  }
  FUN_005c7c10(puVar3 + 0xe,in_ECX + 0x1c);
LAB_005c74e9:
  unaff_EDI[1] = unaff_EDI[1] + 0x2c;
  ExceptionList = local_10;
  return;
}

