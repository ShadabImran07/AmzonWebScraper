"use client";
import { scrapeAndStoreProduct } from "@/lib/actions";
import { FormEvent, useState } from "react";

const Searchbar = () => {
	const [searchPrompt, setSearchStatePrompt] = useState("");
	const [isLoading, setIsLoading] = useState(false);
	const isValidAmazonProductURL = (url: string) => {
		try {
			const parsedURL = new URL(url);
			const hostname = parsedURL.hostname;
			if (
				hostname.includes("amazon.in") ||
				hostname.includes("amazon.com") ||
				hostname.endsWith("amazon")
			) {
				return true;
			}
		} catch (e) {
			return false;
		}
	};
	const handleSubmit = async (e: FormEvent<HTMLFormElement>) => {
		e.preventDefault();
		const isValidLink = isValidAmazonProductURL(searchPrompt);
		if (!isValidLink) {
			alert("Please enter a valid Amazon Product URL");
			setSearchStatePrompt("");
			return;
		}
		try {
			setIsLoading(true);
			const product = await scrapeAndStoreProduct(searchPrompt);
		} catch (e) {
			console.log(e);
		} finally {
			setIsLoading(false);
		}
	};
	return (
		<form
			className='flex flex-wrap gap-4 mt-12'
			onSubmit={handleSubmit}
		>
			<input
				type='text'
				value={searchPrompt}
				onChange={(e) => setSearchStatePrompt(e.target.value)}
				placeholder='Enter a Product Link'
				className='searchbar-input'
			/>

			<button
				type='submit'
				className='searchbar-btn'
				disabled={searchPrompt === ""}
			>
				{isLoading ? "Searching..." : "Search"}
			</button>
		</form>
	);
};

export default Searchbar;
