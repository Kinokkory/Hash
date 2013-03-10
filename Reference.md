# Hash Ver 0.01 Reference

## Binaries in Directory "Code"

* main.exe : Just interpret into C++11 code. It uses standard input/output. You can use it like
<pre>main &lt;a.hash</pre>

* Compile.exe : Compile with g++. You can use it like
<pre>compile a.hash -oa.exe</pre>

## Point

* The grammar of Hash is quite similar to C++.
* Expressions and statements are very similarly treated.
* Every definition will be automatically pre-declared.

## Comment

	/*a*/ ===> //a
	/*a/*b*/c*/ ===>
		//a
		////b
		//c
	/*/ ===> (nothing)
	//a
	</code></pre>

## Type

	A
	var ===> auto
	val ===> const auto
	ref ===> auto&
	rref ===> auto&&
	decltype
	const A
	mutable A
	A*
	A&
	A&&
	A! ===> const A
	A->B ===> Hash::Function&lt;A,B&gt;
	(A,B) ===> Hash::Tuple&lt;A,B&gt;
	[A] ===> Hash::List&lt;A&gt;


## Name

	a
	n::a
	int
	return ===> returnNotReservedWord


## Literal

	123
	'x'
	"foo"


## Expression

	x
	if(x) y else z ===> x?y:z
	\(A x,B y){} ===> [&](A x,B y){}
	\(A x,B y)->C{} ===> [&](A x,B y)->C{}
	{return x;} ===> [&](){return x;}
	{x;} ===> [&](){x;return Hash::unit;}
	(x,y) ===> Hash::makeTuple(x,y)
	() ===> Hash::unit
	[x,y] ===> Hash::makeList(x,y)


## Statement

	x;
	{x;}
	if(x){}
	if(x){}else{}
	for(x;y;z){}
	while(x){}
	until(x){} ===> while(!x){}
	dowhile(x){} ===> do{}while(x)
	dountil(x){} ===> do{}while(!x)
	return x;
	return;
	continue;
	break;


## Variant

	extern A x,y;
	A x=0,y;
	A* x,y; ===> A *x, *y;


## Function

	R f(A x,B y);
	R f(A x,B y){}
	R f<T,int x>(){} ===> template&lt;typename T,int x&gt; R f(){}
	R f(A x,B y)=x; ===> R f(A x,B y){return x;}


## Enum

	enum A{x=0,y} ===> enum A{x=0,y};
	bitenum A{x,y,z} ===> enum A{x=1,y=2,z=4};


## Class/Struct

	class A{} ===> class A{};
	class A{public int x;} ===> class A{public: int x;};
	class A&lt;T,int x&gt;{} ===> template&lt;typename T,int x&gt; class A{};
	class A where c {} ===> class A{static_assert(...);};


## Where

	where c1,c2 ===> static_assert(...);static_assert(...);
	where a ===> static_assert(a,"DOESN'T MATCH STATIC CONDITION");
	where A :=: B ===> static_assert(Hash::is_same&lt;A,B&gt;::value,"DOESN'T MATCH TYPE CONDITION");
	where A :>: B ===> static_assert(Hash::is_base_of&lt;A,B&gt;::value,"DOESN'T MATCH TYPE CONDITION");
	where A :<: B ===> static_assert(Hash::is_base_of&lt;B,A&gt;::value,"DOESN'T MATCH TYPE CONDITION");
	where A :is: abstract ===> static_assert(Hash::is_abstract&lt;A&gt;::value,"DOESN'T MATCH TYPE CONDITION");
	where A :has: nothrow_assign ===> static_assert(Hash::has_nothrow_assign<A>::value,"DOESN'T MATCH TYPE CONDITION");
