
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0088bfdb(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8,
                 double *param_9)

{
  uint *puVar1;
  char cVar2;
  ushort uVar3;
  ushort ****ppppuVar4;
  int in_ECX;
  uint uVar5;
  undefined4 ****ppppuVar6;
  float10 fVar7;
  undefined4 ***local_58;
  double *local_54;
  int local_50;
  undefined4 ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  ushort ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_8;
  uStack_4 = 0x4c;
  local_8 = 0x88bfe7;
  local_54 = param_9;
  FUN_0088a2d6(local_30,&param_2,&param_4,param_6,param_7);
  local_8 = 0;
  cVar2 = equal(&param_4);
  if (cVar2 != '\0') {
    *puVar1 = *puVar1 | 1;
  }
  if (local_20 == 0) {
    *puVar1 = *puVar1 | 2;
    goto LAB_0088c10e;
  }
  uVar3 = FUN_004303a0(0x30,0,in_ECX + 8);
  uVar5 = 0;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = (undefined4 ***)((uint)local_4c[0] & 0xffffff00);
  local_8 = CONCAT31(local_8._1_3_,1);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::reserve
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_4c,local_20);
  ppppuVar4 = (ushort ****)local_30[0];
  if (local_1c < 8) {
    ppppuVar4 = local_30;
  }
  if (*(ushort *)ppppuVar4 < uVar3) {
LAB_0088c090:
    uVar5 = 1;
    FUN_00429630(1,0x2d);
  }
  else {
    ppppuVar4 = (ushort ****)local_30[0];
    if (local_1c < 8) {
      ppppuVar4 = local_30;
    }
    if (uVar3 + 9 < (uint)*(ushort *)ppppuVar4) goto LAB_0088c090;
  }
  for (; uVar5 < local_20; uVar5 = uVar5 + 1) {
    ppppuVar4 = (ushort ****)local_30[0];
    if (local_1c < 8) {
      ppppuVar4 = local_30;
    }
    FUN_00429630(1,((char)*(ushort *)((int)ppppuVar4 + uVar5 * 2) - (char)uVar3) + '0');
  }
  ppppuVar6 = (undefined4 ****)local_4c[0];
  if (local_38 < 0x10) {
    ppppuVar6 = local_4c;
  }
  local_50 = 0;
  fVar7 = (float10)FUN_00890bf5(ppppuVar6,&local_58,0,&local_50);
  if (((undefined4 ****)local_58 == ppppuVar6) || (local_50 != 0)) {
    *puVar1 = *puVar1 | 2;
  }
  else {
    *local_54 = (double)fVar7;
  }
  FUN_00402f30(1,0);
LAB_0088c10e:
  *param_1 = param_2;
  param_1[1] = param_3;
  FUN_00402a00(1,0);
  FUN_0089dbbc();
  return;
}

