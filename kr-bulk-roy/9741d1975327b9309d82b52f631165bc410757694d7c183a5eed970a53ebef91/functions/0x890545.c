
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00890545(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 double *param_9)

{
  uint *puVar1;
  bool bVar2;
  char ****ppppcVar3;
  uint uVar4;
  undefined4 ****ppppuVar5;
  float10 fVar6;
  undefined4 ***local_58;
  double *local_54;
  int local_50;
  undefined4 ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_8;
  uStack_4 = 0x4c;
  local_8 = 0x890551;
  local_54 = param_9;
  FUN_0088f683(local_30,&param_2,&param_4,param_6,param_7);
  local_8 = 0;
  bVar2 = std::istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_2,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_4);
  if (bVar2) {
    *puVar1 = *puVar1 | 1;
  }
  if (local_20 == 0) {
    *puVar1 = *puVar1 | 2;
    goto LAB_00890653;
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffffff00);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::reserve
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_4c,local_20);
  uVar4 = 0;
  ppppcVar3 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar3 = local_30;
  }
  if (*(char *)ppppcVar3 < '0') {
LAB_008905dd:
    uVar4 = 1;
    FUN_00429630(1,0x2d);
  }
  else {
    ppppcVar3 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar3 = local_30;
    }
    if ('9' < *(char *)ppppcVar3) goto LAB_008905dd;
  }
  for (; uVar4 < local_20; uVar4 = uVar4 + 1) {
    ppppcVar3 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar3 = local_30;
    }
    FUN_00429630(1,*(char *)((int)ppppcVar3 + uVar4));
  }
  ppppuVar5 = (undefined4 ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppuVar5 = local_4c;
  }
  local_50 = 0;
  fVar6 = (float10)FUN_00890bf5(ppppuVar5,&local_58,0,&local_50);
  if (((undefined4 ****)local_58 == ppppuVar5) || (local_50 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *local_54 = (double)fVar6;
  }
  FUN_00402f30(1,0);
LAB_00890653:
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

