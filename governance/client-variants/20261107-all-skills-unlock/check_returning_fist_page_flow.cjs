const fs=require('node:fs'),vm=require('node:vm'),assert=require('node:assert/strict');
const source=fs.readFileSync(process.argv[2],'utf8').split('<script>')[1].split('</script>')[0].replace('refresh();setInterval(refresh,2000);','');
class Element {constructor(value=''){this.value=value;this.options=[];this.children=[];this.dataset={};this.textContent='';}add(o){this.options.push(o);}replaceChildren(){this.options=[];this.children=[];}append(o){this.children.push(o);}}
const elements={};for(const id of ['status','labRole','labMatrix','labTier','labLevel','labEnergy','labTargets','applyLab','labPerKey','labKeys','checkpoint','apply'])elements['#'+id]=new Element();
elements['#labTier'].value='0';elements['#labLevel'].value='1';elements['#labEnergy'].value='1000';elements['#labTargets'].value='Melee';elements['#labLevel'].options=[{value:'1'}];
const base={mask:2,practice:50,active:30,name:'X',enabled:true,status:'CANDIDATE',hp:0,sp:35,mp:30,impactPlan:{returningProjectile:{labRange:65,labSpeed:80,labOutboundDamage:60,labReturnPullDistance:20},enemyFrostbite:{durationSeconds:5,declaredAttackSpeedReductionPercent:20,labMovementSpeedReductionPercent:20},pendingEffects:['ice targeting pending']}};const high={...base,learnedLevel:11,sp:55,mp:50};
const fixture=[{role:4,matrix:0,tier:0,levels:[{learnedLevel:1,keys:[base]}],keyLevels:[{mask:2,practice:50,levels:[{...base,learnedLevel:1},high]}]}];
let catalogueGets=0,statusGets=0,request;
const context=vm.createContext({document:{querySelector:id=>elements[id],createElement:()=>new Element()},Option:class {constructor(text,value){this.text=text;this.value=String(value);}},fetch:async(url,options)=>{
if(url==='/local-test/skills/catalog'){catalogueGets++;return{ok:true,json:async()=>fixture};}
if(url==='/local-test/progress/status?includeSkillCatalogue=false'){statusGets++;return{ok:true,json:async()=>({ready:true,checkpoints:[],skillLabChoices:null})};}
assert.equal(url,'/local-test/progress');request=JSON.parse(options.body);return{ok:true,json:async()=>({message:'queued'})};}});
vm.runInContext(source,context);
(async()=>{await vm.runInContext('refresh()',context);assert.equal(catalogueGets,1);assert.equal(statusGets,1);assert.match(elements['#labKeys'].textContent,/測試拳套：射程65、速度80/);assert.match(elements['#labKeys'].textContent,/去程傷害60／回程拉引20/);assert.match(elements['#labKeys'].textContent,/測試凍傷：5秒/);assert.match(elements['#labKeys'].textContent,/攻速下降20%/);assert.match(elements['#labKeys'].textContent,/移速暫降20%/);assert.match(elements['#labKeys'].textContent,/ice targeting pending/);
const picker=elements['#labPerKey'].children[0];await vm.runInContext('refresh()',context);assert.equal(elements['#labPerKey'].children[0],picker);
const select=picker.children[1];select.value='11';select.onchange();await vm.runInContext('refresh()',context);
assert.equal(catalogueGets,1);assert.equal(statusGets,3);assert.match(elements['#labKeys'].textContent,/SP 55/);
await elements['#applyLab'].onclick();assert.deepEqual(request.practiceLevels,{'50':11});assert.equal(request.targets,'Melee');
console.log('PASS: returning-fist calibration plus frostbite/pending text, one catalogue fetch, preserved picker/level/target POST');})().catch(e=>{console.error(e);process.exitCode=1;});
