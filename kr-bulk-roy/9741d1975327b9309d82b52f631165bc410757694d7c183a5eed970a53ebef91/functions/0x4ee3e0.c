
void FUN_004ee3e0(undefined4 *param_1,code *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 *in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = in_ECX;
  puVar4 = in_ECX;
  while (puVar4 = puVar4 + 3, puVar4 != param_1) {
    local_14 = *puVar4;
    local_10 = puVar4[1];
    local_c = puVar4[2];
    cVar5 = (*param_2)(&local_14,in_ECX);
    puVar2 = puVar4;
    if (cVar5 == '\0') {
      cVar5 = (*param_2)(&local_14,puVar1);
      puVar3 = puVar1;
      while (cVar5 != '\0') {
        *puVar2 = *puVar3;
        puVar2[1] = puVar3[1];
        puVar2[2] = puVar3[2];
        cVar5 = (*param_2)(&local_14,puVar3 + -3);
        puVar2 = puVar3;
        puVar3 = puVar3 + -3;
      }
      *puVar2 = local_14;
      puVar2[1] = local_10;
      puVar2[2] = local_c;
    }
    else {
      for (; in_ECX != puVar2; puVar2 = puVar2 + -3) {
        *puVar2 = puVar2[-3];
        puVar2[1] = puVar2[-2];
        puVar2[2] = puVar2[-1];
      }
      *in_ECX = local_14;
      in_ECX[1] = local_10;
      in_ECX[2] = local_c;
    }
    puVar1 = puVar1 + 3;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

